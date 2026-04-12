# -*- coding: utf-8 -*-
# b

def main():
    n = int(input())
    height_mountains = [ int(_)  for _ in input().split() ]

    height_highest = 0
    count_see_sun = 0

    for mountain in height_mountains:
        if mountain >= height_highest:
            height_highest = mountain
            count_see_sun += 1

    print(count_see_sun)

if __name__ == "__main__":
    main()
