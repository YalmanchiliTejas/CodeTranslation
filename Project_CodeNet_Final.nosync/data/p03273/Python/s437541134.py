H,W=map(int,input().split())
g=''
g2=''
h_removed=0
w_removed=0
for i in range(H):
    ip=input()
    if ip=='.'*W:
        h_removed+=1
    else:
        g+=ip
        
for i in range(W):
    col=''
    for j in range(H-h_removed):
        col+=g[i+j*W]
    if col=='.'*(H-h_removed):
        w_removed+=1
    else:
        g2+=col
        
for i in range(H-h_removed):
    p=''
    for j in range(W-w_removed):
        p+=g2[i+j*(H-h_removed)]
    print(p)