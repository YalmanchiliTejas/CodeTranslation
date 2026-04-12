a = input()
list(a)
for i in range(len(a)):
    if a[i] != "A" and i != len(a)-1 :
        continue
    elif a[i] == "A" :
        if a[i+1] == "C" :
            print("Yes")
            break
    else :
        print("No")