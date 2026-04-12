LEFT = 0
RIGHT = 1
key_dict = {
        LEFT : ["q", "w", "e", "r", "t",
            "a", "s", "d", "f", "g",
            "z", "x", "c", "v", "b",],
        RIGHT : ["y", "u", "i", "o", "p",
            "h", "j", "k", "k", "l",
            "n", "m",],
        }

def get_input():
    data_input = input()
    return data_input

def count_chage_num(data_input):
    change_num = 0
    hand_place = None
    for c in data_input:
        if c in key_dict[LEFT]:
            if hand_place != LEFT:
                change_num += 1
            hand_place = LEFT
        else:
            if hand_place != RIGHT:
                change_num += 1
            hand_place = RIGHT
    if change_num != 0:
        change_num -= 1
    return change_num


if __name__ == "__main__":
    while True:
        data_input = get_input()
        if data_input[0] == "#":
            break
        change_num = count_chage_num(data_input)
        print(change_num)

