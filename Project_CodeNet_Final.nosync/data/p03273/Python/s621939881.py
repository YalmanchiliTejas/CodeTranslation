h,w = map(int,input().split())

al_l = []

for _ in range(h):
    al = list(input())
    al_l.append(al)


for al in al_l:
    for idx, a in enumerate(al):
        tmp = [i[idx] for i in al_l]
        if "#" not in al or "#" not in tmp:
            pass
        else:
            print(a, end="")
    print("")
    