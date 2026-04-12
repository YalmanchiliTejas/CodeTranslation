def resolve():
    h,w=map(int,input().split())
    mass = []
    length=0
    for i in range(h):
        a=list(input())
        if "#" in a:
            mass.append(a)
            length+=1
    for i in reversed(range(w)):
        total=0
        for j in range(length):
            if mass[j][i]==".":
                total+=1
        if total==length:
            for j in range(length):
                del mass[j][i]
    for i in range(length):
        print("".join(mass[i]))

resolve()