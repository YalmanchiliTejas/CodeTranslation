n = int(input())

h = list(map(int,input().split(sep=" ")))

ans=0

for i in range(len(h)):
    tmp = h[0:i+1]
    if(h[i] == max(tmp)):
        ans += 1


print(ans)
