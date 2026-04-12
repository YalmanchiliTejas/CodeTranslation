
N = int(input())
S = []
nagasa = 51
for i in range(N):
    dam = input()
    S.append(dam)
    if len(list(dam)) < nagasa:
        nagasa = len(list(dam))
        saisyo=i
# print(S,saisyo)

flg=[0]*len(S[saisyo])
for i in range(len(S[saisyo])):
    for j in range(N):
        if j==saisyo:
            continue
        else:
            for k in range(len(S[j])):
                if S[saisyo][i] == S[j][k]:
                    flg[i] +=1
                    l = list(S[j])
                    l[k] = 'A'
                    S[j] = ''.join(l)
                    # print(i,j,k,S)
                    break

out=[]
for i in range(len(S[saisyo])):
    if flg[i]==N-1:
        out.append(S[saisyo][i])
out=sorted(out)
# print(flg,oust)
print(''.join(out))
