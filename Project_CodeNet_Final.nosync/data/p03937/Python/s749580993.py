H, W = map(int, input().split())
count = 0
for _ in range(H):
    a = input()
    count += a.count('#')
 
if count == H + W - 1:
    print('Possible')
else:
    print('Impossible')