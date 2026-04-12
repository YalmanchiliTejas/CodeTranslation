A =int(input())
B=input()
c=int(input())
d=B[c-1]
E=""
for i in range(A):
    if B[i]==d:
        E=E+d
    else:
        E=E+"*"
print(E)