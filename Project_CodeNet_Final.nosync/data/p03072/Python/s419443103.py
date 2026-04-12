N = int(input())
H = list(map(int, input().split(" ")))
cnt=0
for i in range(N):
    if i==0:
        cnt+=1
    else:
        h=H[i]
        c=0
        for j in range(i):
            if H[j]>h:
                c=1
        if c==0:
            cnt+=1
print(cnt)
