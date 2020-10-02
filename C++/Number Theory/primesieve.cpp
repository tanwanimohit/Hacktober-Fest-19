#include<bits/stdc++.h>

using namespace std;


// O(sqrtN)
bool isPrime(int n){
    if(n == 1){
        return false;
    }else if(n == 2){
        return true;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            return false;
        }
    }
}

// Sieve Approach- Generate array containing Prime numbers
vector<bool> primesieve(int n){
    vector<bool> isp(n+1, true);
    for(int i=2; i*i<=n; i++){ // i*i because the inner loop will run for only sqrtN times 
        if(isp[i] == true){
            for(int j=i*i; j<=n; j+=i)// i*i because before that already have been falsed
                isp[j] = false;
        }
    }
    return isp;
}

int main(){
	int n;
	cin >> n;
	vector<int> result;
	result = sieve(n);
	for(bool i: result) cout << i << " ";
}
