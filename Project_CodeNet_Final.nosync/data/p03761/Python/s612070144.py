#n = int(input())
#n,k = map(int,input().split())
#x = list(map(int,input().split()))

li = list("abcdefghijklmnopqrstuvwxyz")

n = int(input())

memo = [50 for i in range(len(li))]
for i in range(n):
    cnt = [0 for i in range(len(li))]
    s = list(input())
    for j in range(len(s)):
        for l in range(26):
            if s[j] == li[l]:
                cnt[l] += 1

    for j in range(len(li)):
        memo[j] = min(memo[j],cnt[j])

    

for j in range(len(li)):
    for i in range(memo[j]):
        print(li[j],end="")

print()




