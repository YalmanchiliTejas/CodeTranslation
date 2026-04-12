def countInRangeUtil(pos, cnt, tight, num): 
  
    # Last position 
    if pos == len(num): 
  
        # If count of non zero digits 
        # is less than or equal to K 
        if cnt <= K: 
            return 1
        return 0
  
    # If this result is already computed 
    # simply return it 
    if dp[pos][cnt][tight] != -1: 
        return dp[pos][cnt][tight] 
  
    ans = 0
  
    # Maximum limit upto which we can place 
    # digit. If tight is 1, means number has 
    # already become smaller so we can place 
    # any digit, otherwise num[pos] 
    limit = 9 if tight else num[pos] 
  
    for dig in range(limit + 1): 
        currCnt = cnt 
  
        # If the current digit is nonzero 
        # increment currCnt 
        if dig != 0: 
            currCnt += 1
  
        currTight = tight 
  
        # At this position, number becomes 
        # smaller 
        if dig < num[pos]: 
            currTight = 1
  
        # Next recursive call 
        ans += countInRangeUtil(pos + 1, currCnt, currTight, num) 
  
    dp[pos][cnt][tight] = ans 
    return dp[pos][cnt][tight] 
  
# This function converts a number into its 
# digit vector and uses above function to compute 
# the answer 
def countInRange(x): 
    global dp, K, M 
  
    num = [] 
    while x: 
        num.append(x % 10) 
        x //= 10
  
    num.reverse() 
  
    # Initialize dp 
    dp = [[[-1, -1] for i in range(M)] for j in range(M)] 
    return countInRangeUtil(0, 0, 0, num) 
  

a = int(input())
b = int(input())
dp = [] 

M = 100
R = a
K = b
m = countInRange(R)

dp = [] 
M = 100
R = a
K = b - 1
n = countInRange(R)

print(m - n)