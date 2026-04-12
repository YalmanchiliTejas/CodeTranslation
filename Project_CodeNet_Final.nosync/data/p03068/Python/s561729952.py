N=input()
S=input()
reserve = S[int(input())-1]

for i in S:
    if i == reserve:
        print(reserve,end='')
    else:
        print('*', end='')
print()