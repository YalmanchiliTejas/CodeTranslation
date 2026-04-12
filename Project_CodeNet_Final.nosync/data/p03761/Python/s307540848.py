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
N=int(input())
M=list(input())
for i in range(N-1):
  S=list(input())
  M=intersect_list(M,S)
M=sorted(M)
print("".join(M))