n=int(input())
li = list(map(int,input().split()))
cnt=0
for i in range(n):
    if li[i] == max(li[:i+1]):
        cnt += 1

print(cnt)