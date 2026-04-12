h,w=map(int,input().split())
a=str()
for i in range(h):
    a+=input()
print('Possible' if a.count('#')==int(h)+int(w)-1 else 'Impossible')