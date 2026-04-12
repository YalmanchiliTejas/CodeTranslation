N = int(input())
H = list(map(int,input().split(" ")))

W = H[0]
count = 1
for i in range(1,len(H)):
    if W <= H[i]:
        count += 1
        W = H[i]
print(count)