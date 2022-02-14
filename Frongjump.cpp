// There is a frog on the 1st step of an N stairs long staircase. The frog wants to reach the Nth stair. HEIGHT[i] is the height of the (i+1)th stair.If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.In the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair. Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.
#include <iostream>
#include <vector>
using namespace std;

//recurrsion solution

int help(vector<int> &heights,int index){
    if(index == 0)
    return 0;
        int left , right = 1e9;
        left = help(heights,index-1) + abs(heights[index]-heights[index-1]);

    if(index > 1)
    right = help(heights,index-2) + abs(heights[index]-heights[index-2]);

    return min(left,right);
}

//memoization bottom up approach
int help1(vector<int> &heights,vector<int> &mem,int index){
    if(index == 0)
    return 0;

    if(mem[index] != -1)
    return mem[index];

        int left , right = 1e9;
        left = help1(heights,mem,index-1) + abs(heights[index]-heights[index-1]);

    if(index > 1)
    right = help1(heights,mem,index-2) + abs(heights[index]-heights[index-2]);

    return mem[index] = min(left,right);
}

int help2(vector<int> &heights,vector<int> &dp){
    int left , right = 1e9;
    int index = heights.size()-1;
    for(int i=1;i<heights.size();i++){
        left = dp[i-1] + abs(heights[i] - heights[i-1]);

        if(i > 1){
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left,right);
    }
    return dp[index];
}

int main(){
    vector<int> heights = {10,20,30,10};
    int index = heights.size() - 1;

    //recurrsive solution call
    // cout << help(heights,index);

    //memoization bottom up call function
    // vector<int> mem(index+1,-1);
    // cout << help1(heights,mem,index);

    //top-down approach
    vector<int> dp(index+1);
    dp[0] = 0;
    cout << help2(heights,dp);


    return 0;
}