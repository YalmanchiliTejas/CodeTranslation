s = input()
l = len(s)
K = int(input())
def com(x,y):
    child = 1
    mother = 1
    for i in range(y):
        child = child * (x-i)
        mother = mother * (i+1)
    if x == 1 and y >=2:
        return 0
    else:    
        return int(child / mother)
tasumae = (9**K)*com(l-1,K) #与えられた数字よりも一桁少ない999999999・・・までの個数
li = list(s)
doko = []
if l < K:
    print(0)
    exit()
if K == 1:
    print(tasumae+int(li[0]))
    exit()
for i in range(1,l):
    if li[i] != "0":
        doko.append(i)
if K == 2:
    if not doko:
        print(tasumae)
        exit()
    ans = int(li[doko[0]]) + 9*(l-1-doko[0]) + tasumae + (int(li[0])-1)*com(l-1,1)*9
    print(ans)
    exit()
if len(doko) == 0:
    print(tasumae)
    exit()
if len(doko) == 1:
    ans = (int(li[0])-1)*com(l-1,2)*(9**2) + (int(li[doko[0]])-1) * 9 * (l-1-doko[0]) + com(l-1-doko[0],2)*(9**2) + tasumae
    print(ans)
    exit()
ans = (int(li[0])-1)*com(l-1,2)*(9**2) + (int(li[doko[0]])-1) * 9 * (l-1-doko[0]) + int(li[doko[1]]) + 9*(l-1-doko[1]) + com(l-1-doko[0],2)*(9**2) + tasumae
print(ans)