#include<bits/stdc++.h>
#define take_input freopen("input.txt", "r", stdin)
#define ll long long int
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

// to find the factors of a number you just jhave to use the \
signature loop of "finding whether a number is prime or not"

// To find prime factorization of a number
template <typename T>
vector<T> primeFactor(T n){
	vector<int> spf(n+1, 0);
	for(int i=0; i<=n; i++){
		spf[i] = i;
	}
	for(int i=2; i*i<=n; i++){
		if(spf[i] == i){
			for(int j=i*i; j<=n; j+=i){
				if(spf[j] == j) spf[j] = i;
			}
		}
	}
	return spf;
}

int main(){
	int x;
	cin >> x;
	vector<int> spf = primeFactor(x);
	vector<int> v;
	while(x != 1){
		v.push_back(spf[x]);
		x /= spf[x];
	}
	for(int i:v) cout << i << " ";
	cout << "\n";
}