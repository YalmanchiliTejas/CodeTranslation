H,W = map(int,input().split())
count = 0
for i in range(H):
    a = input()
    count += a.count("#")
if count == H + W - 1:
    ans = "Possible"
else:
    ans = "Impossible"
print(ans)