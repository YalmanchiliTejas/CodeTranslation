n = int(input())
s = list(map(int, input().strip().split()))

top = s[0]
cnt = 0
for i in range(n):
    if(s[i] >= top):
        top = s[i]
        cnt += 1


print (cnt)