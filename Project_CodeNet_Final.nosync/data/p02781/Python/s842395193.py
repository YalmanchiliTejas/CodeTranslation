n_ = input()
n = int(n_)
k = int(input())

#kが小さい
#100桁から2か所,1~9二回選択
#ちょうどk個

ans = 0
l = len(n_) 
ans += int(n_[0])+9*(l-1)
if k==1:
    print(ans)
    exit()
ans = 0
ans += 9*9*(l-2)*(l-1)//2
ans += (int(n_[0])-1)*9*(l-1)
tmp = int(n_[0])*10**(l-1)
for j in range(1,10):
    for i in range(len(n_)):
        if n>=tmp+j*10**i:
            ans += 1
if k==2:
    print(ans)
    exit()
    
ans = 0

ans += 9*9*9*(l-2)*(l-1)*(l-3)//6
ans += (int(n_[0])-1)*9*9*(l-1)*(l-2)//2
tmp = int(n_[0])*10**(l-1)
for j in range(1,10):
    for k in range(1,10):
        for i in range(len(n_)):
            for h in range(i):
                if n>=tmp+j*10**i+k*10**h:
                    ans += 1
print(ans)
    


