N=int(input())
H=[int(x) for x in input().split()]
cnt=1
tall=H[0]
for i in range(1,N):
    if tall<=H[i]:
        tall=H[i]
        cnt+=1
print(cnt)
