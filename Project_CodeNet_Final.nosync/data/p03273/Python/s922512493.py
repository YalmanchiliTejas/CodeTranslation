h, w = map(int, input().split())
array = [input() for i in range(h)]


def delete(array):
    for i in range(len(array) - 1, -1, -1):
        if ''.join(list(set(list(array[i])))) == '.':
            del array[i]

delete(array)
array = list(map(list, zip(*array)))
delete(array)
array = list(map(list, zip(*array)))

for i in range(len(array)):
    print (''.join(array[i]))
