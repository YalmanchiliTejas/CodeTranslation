N = int(input())
H = list(map(int, input().split()))
m = 0
cout = 0
for i in range(N):
    if m <= H[i]:
        cout += 1
    m = max(m, H[i])
print(cout)
