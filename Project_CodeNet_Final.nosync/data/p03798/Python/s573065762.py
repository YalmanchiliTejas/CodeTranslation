
def reset(n):
    a = [0 for i in range(n+2)]
    return a
    
n = int(input())
s = list(input())
s.append(s[0])

dt = [[1,1],[-1,1],[1,-1],[-1,-1]] #1→sheep,-1→wlf

ans = False
for i in range(4):
    li = reset(n)
    li[0] = dt[i][0]
    li[1] = dt[i][1]

    for j in range(1,len(s)):
        if s[j] =='o':
            li[j+1] = li[j]*li[j-1]
        elif s[j] =='x':
            li[j+1] = li[j]*li[j-1]*(-1)
    if li[0]==li[n] and li[1]==li[n+1]:
        ans = True
        break

if (ans):
    for i in range(n):
        if li[i] == 1:
            print('S',end="")
        else:
            print('W',end="")
    print('')

else:
    print(-1)

