#include "volunteer.h"
#include "read_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct volunteer *add_to_list(struct volunteer *list) { // This function allows a user to add a volunteer to the list


  char l[NAME_LEN + 1] = ""; // Initialize last, first, and email members with an empty string
  char f[NAME_LEN + 1] = ""; 
  char e[EMAIL_LEN + 1] = "";
  int g; // Initialize grade-level variable

  printf("Enter last name: "); // User input; calls read_line and scanf; saves input in last, first, email, and grade-level
  read_line(l,NAME_LEN+1);
  printf("Enter first name: ");
  read_line(f,NAME_LEN+1);
  printf("Enter email address: ");
  read_line(e,EMAIL_LEN+1);
  printf("Enter grade level: ");
  scanf("%d", &g);

  struct volunteer *new_volunteer=malloc(sizeof(struct volunteer)); // Allocates space for user input 
  if(new_volunteer==NULL){ // Allocation test
    printf("malloc failed in add_to_list");
    return list;
  }

  strcpy(new_volunteer -> last, l); // Stores user input in members of new volunteer node
  strcpy(new_volunteer -> first, f);
  strcpy(new_volunteer -> email, e);
  new_volunteer->grade_level = g;
  new_volunteer->next = NULL; // Sets next pointer to NULL

  if (list == NULL) { // If the list is empty, return pointer to new volunteer node
    return new_volunteer;
  }

  struct volunteer *current = list; // Condition for where list has preexisting data; sets current node to last element of list


  while(current -> next != NULL){ // Traverses list until the end of the list is reached; ensures that the user input does not match preceding data


    if((strcmp(current ->last, l)==0) && (strcmp(current ->first, f)==0) && (strcmp(current ->email, e)==0) && (current ->grade_level==g)){
      
      printf("volunteer already exists.\n");
      
      return list;
    }
    current=current -> next; // Moves to next node
  }
  current->next = new_volunteer; // Appends new volunteer node to end of list

  return list;
}

struct volunteer *delete_from_list(struct volunteer *list){ // This function allows a user to delete a volunteer from the list; it uses a while loop with if statements to find the node matching the user input and frees the memory associated with that node

  struct volunteer *cur=list, *prev=NULL; // Initialize current and previous nodes

  char l[NAME_LEN + 1] = ""; // Initialize last, first, and email members with an empty string
  char f[NAME_LEN + 1] = ""; 
  char e[EMAIL_LEN + 1] = "";
  int g; // Initialize grade-level variable

  printf("Enter last name: "); // User input; calls read_line and scanf; saves input in last, first, email, and grade-level
  read_line(l,NAME_LEN+1);
  printf("Enter first name: ");
  read_line(f,NAME_LEN+1);
  printf("Enter email address: ");
  read_line(e,EMAIL_LEN+1);
  printf("Enter grade level: ");
  scanf("%d", &g);

  while (cur != NULL) { // Traverses list until the end of the list is reached

    if (strcmp(cur->last, l) == 0 && strcmp(cur->first, f) == 0 && strcmp(cur->email, e) == 0 && cur->grade_level == g) { // If the user input matches the data of a volunteer, delete the node

      if (prev == NULL)
        list = cur->next; /* If the node to be deleted is the first node */

      else
        prev->next = cur->next; /* If the node to be deleted is not the first node */

      free(cur); // Free the current node
      return list; 
    }

    prev = cur; // Move to next node
    cur = cur->next; 
  }
    printf("volunteer does not exist\n");
    return list;
}

void search_list(struct volunteer *list) // This function allows a user to search for a volunteer by grade level 
{

  int g; // Initialize grade-level variable

  int count=0; // Initialize count variable for condition where volunteer DNE

  printf("Enter grade level: "); // User input for grade level
  scanf("%d", &g);

  struct volunteer *current = list; // Sets current node to first element of list

  while(current != NULL){ // Traverses list until the end of the list is reached

    if(current -> grade_level == g){ // If the user input matches the grade level of a volunteer, print the volunteer's information

      printf("%-12s%-12s%-30s\n", current -> last, current -> first, current -> email);

      count++; // Increments count
    }

    current=current -> next; // Moves to next node
  }

  if(current==NULL && count == 0){ // If the user input does not match any grade levels, print "not found"

    printf("not found\n");
  }
}


void print_list(struct volunteer *list){ // This function prints the list of volunteers
  struct volunteer *current=list; // Sets current node to first element of list

  while(current != NULL){ // Traverses list until the end of the list is reached

    printf("%-12s%-12s%-30s%5d\n", current -> last, current -> first, current -> email, current -> grade_level);

    current=current -> next; // Moves to next node
  }
}


void clear_list(struct volunteer *list) {
    struct volunteer *current = list;
    struct volunteer *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}