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

int bt(int i, int skips, int score){

	if(i > n){
		return score;
	}

	// if it is a super task
	if(r[i] == -1){

		if(skips != 0){
			return min( bt(i+1,skips-1,score) , bt(i+m,skips,score+t[i]) );
		}

		return bt(i+m,skips,score+t[i]);
	
	}

	if(skips != 0){
		return min( bt(i+1,skips-1,score) , bt(i+1,skips+r[i],score+t[i]) );
	}

	return bt(i+1,skips+r[i],score+t[i]);

}

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

	best = min(best,bt(1,0,0));

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