import numpy as np


if __name__ == '__main__':
    N = int(input())
    heights = np.array([int(x) for x in input().split(' ')])
    max_height = heights[0]
    num_viewable = 1
    for height in heights[1:]:
        if height >= max_height:
            num_viewable += 1
            max_height = height
    print(num_viewable)
