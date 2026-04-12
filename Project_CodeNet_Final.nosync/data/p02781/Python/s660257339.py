s = input()
d = len(s)
n = int(s)
k = int(input())

top = int(s[0])



def k_2(s):
    d = len(s)
    top = int(s[0])
    first_non_zero = -1
    first_pos = -1
    for i in range(1, d):
        if s[i] != '0':
            first_non_zero = int(s[i])
            first_pos = d - i
            break
    x = ((d-2) * (d-1) // 2) * 81
    y =  (top-1) * 9 * (d-1)
    z = first_non_zero + (first_pos-1) * 9 if first_pos >= 0 else 0
    return (x+y+z)    


if k == 1:
    print((d-1) * 9 + top)

elif k == 2:
    print(k_2(s))

else:
    x = ((9 ** 3) * (((d-3)*(d-2)*(2*d-5) // 6) + ((d-3)*(d-2) // 2)) //2)
    y = (top-1) * 81 * ((d-1)*(d-2) // 2)
    
    first_non_zero = -1
    ind = -1
    for i in range(1, d):
        if s[i] != '0':
            ind = i
            break
    z = k_2(s[ind:])
    # print(x)
    # print(y)
    # print(z)
    print(x + y + z)