N=int(input())
S=input()
K=int(input())

for index,value in enumerate(S,start=1):

    if value != S[K-1] :

        S = S.replace(value,'*')

    elif value == '*' or value == S[K-1]:

        continue


print(S)