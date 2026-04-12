H,W = map(int,input().split())
suma = 0
for i in range(H):
    a = input()
    suma += a.count('#')
if suma == H+W-1:
    print('Possible')
else:
    print('Impossible')
