n=int(input())
c={chr(ord('a') +i): 0 for i in range(26)}

for s1c in input():
    c[s1c] += 1

for i in range(1,n):
    c2={chr(ord('a') +i): 0 for i in range(26)}
    for j in input():
        c2[j] += 1
    for j in range(ord('a'),ord('z')+1):
        c[chr(j)] = min(c[chr(j)],c2[chr(j)])

for i in range(ord('a'),ord('z')+1):
    print(chr(i)*c[chr(i)],end="")
print()
