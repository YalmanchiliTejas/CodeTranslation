# -*- coding: utf-8 -*-

# AtCoder Beginner Contest
# Problem B

if __name__ == '__main__':
    total_width, width_per_person, span = list(map(int, input().split()))

    result = (total_width - span) // (width_per_person + span)
    print(result)
