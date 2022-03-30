#include<bits/stdc++.h>
#define ll long long
#define ld long double
//#define M_PI (2*acos(0))
#define MAX_N 10001
#define MOD 1000000007
#define apo(a,b) sqrtl( powl(a.x-b.x,2) + powl(a.y-b.y,2) )
#define ldeq(a,b) ( fabsl(a - b) < 0.00000000007 )
#define rep(a,b) for(int i=a; i<=b; i++)
#define repv(a,b,i) for(int i=a; i<=b; i++)
#define mmod(a,b) ( (a >= 0) ? ((a%b)%b) : ( ( ( a + ( ((abs(a)+b)/b) * b ) ) % b ) % b ) )
#define int ll
#define ALL(x) x.begin(),x.end()
#define S(x) ((int)(x.size()))
#define PB push_back
using namespace std;

#define MAXSIEVE 1
// Uncomment the next two lines when you want to use the sieve
//#undef MAXSIEVE
//#define MAXSIEVE (1000000000LL+1)
bool is_not_prime[MAXSIEVE]; 
vector < long long > sieve(long long N){

	vector < long long > primes;

	is_not_prime[1] = is_not_prime[0] = 1;
	
	primes.push_back(2);
	for(long long i=3;i<=N;i+=2){
		if(is_not_prime[i] == 0){
			primes.push_back(i);
			for(long long j=i*i;j<=N;j+=i){
				is_not_prime[j] = 1;
			}
		}
	}

	return primes;

}

int n,m,k;
int t[10001];
int r[10001];
// only keeping 101 ones since M<=100 and play with modulo
// 0..100 modulos of 101
int dp[101][10001];

void doit(){

	cin >> n >> m >> k;

	// let's get the best position to be when we do all the tasks
	int best = 0;

	rep(1,n){
		cin >> t[i];
		best += t[i];
	}

	rep(1,n){

		string x;
		cin >> x;

		if( (S(x) == 1) && (x[0] == 'S') ){
			r[i] = -1;
		}
		else{
			r[i] = atoi(x.c_str());
		}

	}

	// now we run the dp
	
	// initiallize all cases to be inaccessible
	rep(0,100){
		repv(0,k,j){
			dp[i][j] = -1;
		}
	}

	dp[1][0] = 0;

	rep(1,n){

		int modi = i % 101; // modulo 101 -> 0 .. 100

		// initiallize M places ahead cause we can't reach before but now we can
		if( i+m > n ){
			// no need to initialize
		}
		else{
			repv(0,k,mi){
				dp[(i+m)%101][mi] = -1;
			}
		}

		repv(0,k,j){
			
			// if the case is accessible then we solve
			if(dp[modi][j] != -1){

				// super task
				if(r[i] == -1){

					// complete the task
					if( i + m > n ){ // finish test
						best = min(best,dp[modi][j]+t[i]);
					}
					else{
						if( dp[(i+m)%101][j] == -1 ){
							dp[(i+m)%101][j] = dp[modi][j] + t[i];
						}
						else{
							dp[(i+m)%101][j] = min(dp[(i+m)%101][j],dp[modi][j]+t[i]);
						}
					}

					// skip the task
					if(j > 0){
						// finish test
						if( i + 1 > n ){
							best = min(best,dp[modi][j]);
						}
						else if( dp[(i+1)%101][j-1] == -1 ){
							dp[(i+1)%101][j-1] = dp[modi][j];
						}
						else{
							dp[(i+1)%101][j-1] = min(dp[(i+1)%101][j-1],dp[modi][j]);
						}
					}

				}
				else{

					// non-super task

					// complete the task
					if( i + 1 > n ){ // finish test
						best = min(best,dp[modi][j]+t[i]);
					}
					else{
						if( dp[ (i+1) % 101 ][ j + r[i] ] == -1 ){
							dp[ (i+1) % 101 ][ j + r[i] ] = dp[modi][j] + t[i];
						}
						else{
							dp[ (i+1) % 101 ][ j + r[i] ] = min( dp[ (i+1) % 101 ][ j + r[i] ] , dp[modi][j] + t[i] );
						}
					}

					// skip the task
					if( j > 0 ){
						// finish test
						if( i + 1 > n ){
							best = min(best,dp[modi][j]);
						}
						else if( dp[ (i+1) % 101 ][ j-1 ] == -1 ){
							dp[ (i+1) % 101 ][ j-1 ] = dp[modi][j];
						}
						else{
							dp[ (i+1) % 101 ][ j-1 ] = min( dp[ (i+1) % 101 ][ j-1 ] , dp[modi][j] );
						}
					}

				}

			}

		}
	}

	cout << best << endl;

}

#undef int
int main(){

	ios::sync_with_stdio(false);
  	cin.tie(0);

	ll t=1;
	//cin>>t;

	while(t--){
		doit();
	}
  	
}