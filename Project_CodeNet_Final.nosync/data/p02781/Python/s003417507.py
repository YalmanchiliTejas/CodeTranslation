#almost everywhere zero

n=input()
k=int(input())
dp_small=[[0 for i in range(4)] for j in range(101)]
dp_same=[[0 for i in range(4)] for j in range(101)]

#dp/smallすでに小さい
#dp_largeまだ小さいかどうかわからない
for i in range(101):
    dp_small[i][0]=1
dp_small[0][0]=0
dp_same[0][0]=1
for i in range(len(n)):
    a=int(n[i])
    #左からi+1番目の桁について考える
    if a!=0:
        dp_small[i+1][1]=dp_small[i][1]+9*dp_small[i][0]+(a-1)*dp_same[i][0]+dp_same[i][1]
        dp_small[i+1][2]=dp_small[i][2]+9*dp_small[i][1]+(a-1)*dp_same[i][1]+dp_same[i][2]
        dp_small[i+1][3]=dp_small[i][3]+9*dp_small[i][2]+(a-1)*dp_same[i][2]+dp_same[i][3]

        dp_same[i+1][1]=dp_same[i][0]
        dp_same[i+1][2]=dp_same[i][1]
        dp_same[i+1][3]=dp_same[i][2]       
        
        
        
        
    elif a==0:
        dp_small[i+1][1]=dp_small[i][1]+9*dp_small[i][0]
        dp_small[i+1][2]=dp_small[i][2]+9*dp_small[i][1]
        dp_small[i+1][3]=dp_small[i][3]+9*dp_small[i][2]

        dp_same[i+1][1]=dp_same[i][1]
        dp_same[i+1][2]=dp_same[i][2]
        dp_same[i+1][3]=dp_same[i][3]
        
L=len(n)
sums= dp_small[L][k]+dp_same[L][k]

print(sums)
