from math import ceil
from itertools import permutations


def main():
    length = int(input())
    numbers = [int(input()) for _ in range(length)]
    numbers.sort()
    number_pair = []
    for i in range(ceil(length / 2) - 1):
        number_pair.append([numbers[i], numbers[-i - 1]])
    number_pair.sort(key=lambda x: x[1])
    side = [numbers[length // 2]]
    if length % 2 == 0:
        side.append(numbers[length // 2 - 1])
    else:
        side.append(-1)
    answer = 0
    if 2 < length:
        for left_side, right_side in permutations(side):
            large_first = 0
            small_first = 0
            for i in range(len(number_pair)):
                if i == 0 and left_side != -1:
                    large_first += abs(left_side - number_pair[i][1])
                    small_first += abs(left_side - number_pair[i][0])
                if i == len(number_pair) - 1 and right_side != -1:
                    large_first += abs(right_side - number_pair[i][0])
                    small_first += abs(right_side - number_pair[i][1])
                if 0 < i:
                    large_first += abs(number_pair[i][1] - number_pair[i - 1][0])
                    small_first += abs(number_pair[i][0] - number_pair[i - 1][1])
                large_first += abs(number_pair[i][0] - number_pair[i][1])
                small_first += abs(number_pair[i][0] - number_pair[i][1])
            answer = max(answer, large_first, small_first)
    else:
        answer = abs(numbers[0] - numbers[1])
    print(answer)


if __name__ == '__main__':
    main()

