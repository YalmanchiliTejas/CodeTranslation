H,W=[int(a) for a in input().split(" ")]
tab=[input() for i in range(H)]
tab2=[]
for row in tab:
    if any([a!="." for a in row]):
        tab2.append(row)
tab = []
for column in zip(*tab2):
    if any([a!="." for a in column]):
        tab.append(column)
for row in zip(*tab):
    print("".join(row))