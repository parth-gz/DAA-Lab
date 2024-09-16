#include <iostream>
#include <vector>
using namespace std;

// Returns the count of ways we can
// sum coinValues[0...numCoins-1] coins to get targetSum
int findWaysToMakeSum(const vector<int>& coinValues, int numCoins, int targetSum) {
  
    // If targetSum is 0 then there is 1 solution
    // (do not include any coin)
    if (targetSum == 0) return 1;

    // 0 ways in the following two cases
    if (targetSum < 0 || numCoins == 0) return 0;

    // count is sum of solutions (i)
    // including coinValues[numCoins-1] (ii) excluding coinValues[numCoins-1]
    return findWaysToMakeSum(coinValues, numCoins, targetSum - coinValues[numCoins - 1]) + 
           findWaysToMakeSum(coinValues, numCoins - 1, targetSum);
}

// Driver code
int main() {
    vector<int> coinValues = {1, 2, 3};
    int targetSum = 5;
    cout << findWaysToMakeSum(coinValues, coinValues.size(), targetSum);
    return 0;
}
