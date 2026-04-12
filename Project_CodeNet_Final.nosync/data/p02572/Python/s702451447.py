n = int(input())
nums = [int(x) for x in input().split()]
multinums = [0]
total = 0

for i in range(0,n):  #累積和配列を作成する
    multinums.append(multinums[i]+nums[i])

#print(multinums)

for i in range(0,n):
    #print(nums[i],multinums[n]-multinums[i+1],nums[i] * (multinums[n]-multinums[i+1]))
    total += nums[i] * (multinums[n]-multinums[i+1])

print(total%(10**9+7))