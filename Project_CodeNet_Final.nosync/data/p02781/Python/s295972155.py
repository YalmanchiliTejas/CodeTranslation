N_str = str(input())
K = int(input())

digit_length = len(N_str)
topmost_digit = int(N_str[0])

C_table = [[0, 0, 0, 0] for _ in range(digit_length+10)]


def C(all, pick):
    if C_table[all][pick] == 0:
        count_child = 1
        count_parent = 1
        for i in range(pick):
            count_child *= all - i
            count_parent *= i + 1
        C_table[all][pick] = count_child // count_parent
    return C_table[all][pick]


def get_count(top_digit, digit_count, needed_nonzero):
    if needed_nonzero <= 0 or needed_nonzero > digit_count:
        return 0

    if digit_count == 1:
        if needed_nonzero == 1:
            return top_digit
        else:
            return 0

    if top_digit == 0:
        return get_count(int(N_str[digit_length - digit_count + 1]) ,digit_count - 1, needed_nonzero)

    if top_digit >= 1:
        count = C(digit_count - 1, needed_nonzero) * (9 ** needed_nonzero)
        if needed_nonzero == 1:
            count += 1

    if top_digit > 1:
        count += C(digit_count - 1, needed_nonzero - 1) * (9 ** (needed_nonzero - 1)) * (top_digit - 1)

    return count + get_count(int(N_str[digit_length - digit_count + 1]) ,digit_count - 1, needed_nonzero - 1)


print(get_count(topmost_digit, digit_length, K))