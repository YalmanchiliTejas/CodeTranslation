def intersect_list(lst1, lst2):
    arr = []
    lst = lst1.copy()
    for element in lst2:
        try:
            lst.remove(element)
        except ValueError:
            pass
        else:
            arr.append(element)
    return arr

n = int(input())
a0 = list(input())
for i in range(n-1):
    a  = list(input())
    a0 = intersect_list(a0, a)

print("".join(sorted(a0)))