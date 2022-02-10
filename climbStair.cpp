#include <iostream>
#include <vector>
using namespace std;

//top down
int f(int n,vector<int> &dp){
    if(n <= 1)
    return 1;

    if(dp[n] != -1)
    return dp[n];

    return dp[n] = f(n-2,dp) + f(n-1,dp);
}

int f1(int n,vector<int> &dp){
    for(int i = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;
    cin >> n;

    //top down
    vector<int> mem(n+1,-1);
    cout << f(n,mem) << endl;;

    //bottom-up
    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    cout << f1(n,dp);
    return 0;
}