N = int(input())

X = input().split()
x1 = [int(x) for x in X]
x2 = [int(x) for x in X]

x2.sort()
ml = x2[int((N/2)-1)]
mr = x2[int(N/2)]

for i in range(N):
    if x1[i] <=  ml:
        print("%d"%mr)
    else:
        print("%d"%ml)
        
    