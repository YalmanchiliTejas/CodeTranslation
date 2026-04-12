n = int(input())
p = list(map(int,input().split()))
q = sorted(p)
if n != 2:
    med_1 = q[n//2-1]
    med_2 = q[n//2]
    
    for i in range(n):
        if p[i] == med_1:
            print(med_2)
        elif p[i] == med_2:
            print(med_1)
        elif p[i] < med_1:
            print(med_2)
        else:
            print(med_1)
else:
    print(p[1])
    print(p[0])