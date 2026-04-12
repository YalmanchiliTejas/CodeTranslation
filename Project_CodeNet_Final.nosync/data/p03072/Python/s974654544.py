N = int(input())
H = list(map(int, input().split()))
#N=3
#H=[2, 5, 4]

ans = 0
for i in range(N):
    c = 0
    #print(H[i])
    #print("a")
    for j in range(i):
        #print(H[i])
        #print("b")
        if H[i]>=H[j]:
            c += 1
            #print(c)
    if c == i:
        #print("c")
        ans += 1
print(ans)
