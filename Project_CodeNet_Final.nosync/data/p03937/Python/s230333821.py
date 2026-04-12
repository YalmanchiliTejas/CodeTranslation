H,W=map(int,input().split())
count=0
for i in range(H):
    Ai=input()
    for c in Ai:
        if c=='#':
            count+=1
ans='Possible' if count==H+W-1 else 'Impossible'
print(ans)