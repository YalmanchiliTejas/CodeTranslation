import bisect

N = int(input())

a = - int(input())

a_array = [a]

for i in range(N-1):
    a = - int(input())
    index = bisect.bisect_right(a_array,a)
    if index == len(a_array):
        a_array.append(a)
    else:
        a_array[index] = a
    # print(a_array)
print(len(a_array))
