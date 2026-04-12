#%%
N, X = map(int, input().split())
point = []
ans = 0

a = 1
p = 1
for i in range(N):
    a *= 2
    a += 3
    p *= 2
    p += 1

#print(a, p)

while a >= 1:
    if X == a :
        ans += p
        break
    elif (a+1)//2+1 <= X <= a-1:
        X -= 2+(a-3)//2
        ans += p//2 + 1
    elif  X == (a+1)//2:
        ans += p//2 + 1
        break
    elif 2 <= X <= (a+1)//2-1:
        X -= 1
    elif X == 1:
        break

    a -= 3
    a //= 2
    p -= 1
    p //= 2

    #print(a, p)

print(ans)


