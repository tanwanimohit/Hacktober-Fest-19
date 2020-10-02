// Binary Search All Variants
#include<bits/stdc++.h>

using namespace std;


// sometimes mid = (lo+hi)/2 can cause overflow
// so we can write mid = lo + (hi-lo)/2 or mid = lo+(hi-lo+1)/2

// Simple Binary Search (Iterative Implementation)
int binarysearch1(int *a, int n, int k){ // O(logN)
    int lg = n-1;
    int sm = 0;
    int mid = (lg+sm)/2;
    while(lg>=sm){
        if(a[mid]>k){
            lg = mid-1;
        }else if(a[mid]<k){
            sm = mid+1;
        }else if(a[mid] == k){
            return mid;
        }
    }
    return -1;
}


// Simple Binary Search (Recursive Implementation)
int binarysearch2(int *a, int k, int high = n-1, int low = 0){
    int mid = (high+low)/2;
    if(a[mid]>k){
        binarysearch2(a, k, high=mid-1);
    }else if(a[mid]<k){
        binarysearch2(a, k, low = mid+1);
    }else if(a[mid] == k){
        return mid;
    }
    return -1;
}

// Array with repeated elements // To get the first occurence
// Example : 2 4 10 10 10 12 20
int binarysearch3(int *a, int n, int k){
    int lg = n-1;
    int sm = 0;
    int result = -1;
    while(lg>=sm){
        int mid = (lg+sm)/2;
        if(a[mid]>k){
            lg = mid-1;
        }else if(a[mid]<k){
            sm = mid+1;
        }else if(a[mid] == k){
            result = mid;
            lg = mid-1; // This is to get the first occurence
        }
    }
    return result;
}

// To get the last occurence
int binarysearch4(int *a, int n, int k){
    int lg = n-1;
    int sm = 0;
    int result = -1;
    while(lg>=sm){
        int mid = (high+low)/2;
        if(a[mid]>k){
            lg = mid-1;
        }else if(a[mid]<k){
            sm = mid+1;
        }else if(a[mid] == k){
            result = mid;
            sm = mid+1; // This is to get the last occurence
        }
    }
    return result;
}

int totalocc(int *a, int n, int k){
    return binarysearch4(a, n, k) - binarysearch3(a, n, k)+1;
}


int main(){

}