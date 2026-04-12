import itertools

N = input()
K = int(input())
lN = len(N)


if K == 1:
    ans = int(N[0])+9*(lN-1)
    print(ans)

elif K == 2:
    not0 = 1000
    for i in range(1,lN):
        if int(N[i]) != 0:
            not0 = i
            break

    ans = 0
    n = [i for i in range(lN)]

    for v in itertools.combinations(n,2):
        #print(v)
        if v[0] != 0:
            ans += 9*9
        else:
            if not0 >= v[1]:
                ans += max(0,int(N[0])-1)*9 + int(N[v[1]])
            else:
                ans += int(N[0])*9
    print(ans)

else:
    not0f = 1000
    not0s = 1000
    for i in range(1,lN):
        if int(N[i]) != 0:
            not0f = i
            break
    for i in range(not0f+1,lN):
        if int(N[i]) != 0:
            not0s = i
            break
    ans = 0
    n = [i for i in range(lN)]
    for v in itertools.combinations(n,3):
        if v[0] != 0:
            ans += 9*9*9
        else:
            if not0f == v[1]:
                if not0s == v[2]:
                    ans += max(0,int(N[0])-1)*9*9
                    ans += max(0,int(N[v[1]])-1)*9
                    ans += int(N[v[2]])
                elif not0s < v[2]:
                    ans += max(0,int(N[0])-1)*9*9
                    ans += int(N[v[1]])*9
                    #ans += int(N[0])*int(N[v[1]])*9
                else:
                    ans += max(0,int(N[0])-1)*9*9
                    ans += max(0,int(N[v[1]])-1)*9
            elif not0f < v[1]:
                ans += int(N[0])*9*9
            else:
                ans += max(0,int(N[0])-1)*9*9

    print(ans)
