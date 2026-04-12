
if __name__ == "__main__":
    n = int(input())
    nums = [int(s) for s in input().split()]
    odds = [0]        
    for num in nums[::2]:
        odds.append(num + odds[-1])
    
    res = [0]
    for i, num in enumerate(nums[1::2]):
        res.append(max(res[-1]+num, odds[i+1]))
    
    if n % 2 == 0:
        print(res[-1])
    else:
        ans = float('-inf')
        for i, r in enumerate(res):
            ans = max(ans, res[i] + odds[-1] - odds[i+1])
        print(ans)

