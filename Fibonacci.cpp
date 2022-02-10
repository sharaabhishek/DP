#include <iostream>
#include <vector>
using namespace std;

// recursive solution
int f(int n){
    if(n <= 1)
    return n;

    return f(n-1) + f(n-2);
}

// memoization technique
int f1(int n,vector<int> &mem){
    if(n <= 1)
    return n;

    if(mem[n] != -1)
    return mem[n];

    return mem[n] = f1(n-1,mem) + f1(n-2,mem);
}

int f2(int n,vector<int> &dp){
    dp[0] = 0, dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+ dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;

    // recursive solution
    cout << f(n) << endl;

    // top-down memmoization technique
    vector<int> mem(n+1,-1);
    cout <<  f1(n,mem) << endl;
    
    //bottom up solution
        vector<int> dp(n+1);
        cout << f2(n,dp);


    return 0;
}