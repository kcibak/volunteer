/*Name: Kira Cibak
Description: This is the header file for the volunteer source file, containing all necessary structures*/

#ifndef volunteer_h
#define volunteer_h

#define EMAIL_LEN 100
#define NAME_LEN 30

struct volunteer{ // Creates volunteer node with 3 strings and an integer
	char first[NAME_LEN+1];
	char last[NAME_LEN+1];
	char email[EMAIL_LEN+1];
	int grade_level;
	struct volunteer *next;
};


struct volunteer *add_to_list(struct volunteer *list); // (21-25) Function declarations
void search_list(struct volunteer *list);
void print_list(struct volunteer *list);
void clear_list(struct volunteer *list);
struct volunteer *delete_from_list(struct volunteer *list);

#endif