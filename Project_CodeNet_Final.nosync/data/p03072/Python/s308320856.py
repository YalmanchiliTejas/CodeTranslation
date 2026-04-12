N = int(input())
mounts =list(map(int, input().split()))
#print(mounts)

counter = 1
comp = []
comp.append(mounts[0])

for mount in mounts[1:]:
    Flag = False
    #print("count{} mount{}".format(counter, mount))
    for c in comp:
        if c > mount:
            Flag = True
            break
    if not Flag:
        counter += 1
    comp.append(mount)
    #print(counter)

print(counter)