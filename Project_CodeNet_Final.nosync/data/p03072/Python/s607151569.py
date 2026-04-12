n=int(input())
h=list(map(int,input().split()))

cnt=0
teppen=h[0]
for i in range(n):
    if teppen<= h[i]:
        cnt+=1
        teppen=h[i]
    else:
        continue
print(cnt)