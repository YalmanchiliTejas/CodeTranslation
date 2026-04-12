import numpy as np


def getInput():
    """

    :return: list of list of str. 1st dim: row, 2nd dim: column.
    """
    separator = ' '
    ret_array = []
    while True:
        try:
            row = input().split(sep=separator)
            ret_array.append(row)
        except EOFError:
            break
    return ret_array


g = getInput()

# number
xyz = np.array(list(map(int, g[0])), dtype=np.int32)
print(np.int32(np.floor((xyz[0] - xyz[2]) / (xyz[1] + xyz[2]))))
