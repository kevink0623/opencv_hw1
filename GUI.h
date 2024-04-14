#ifndef GUI_H
#define GUI_H

// Main window.
#define WINDOW_NAME		"MMTA HW1: TINY PHOTOSHOP"
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	800

// Image panel.
#define MAX_IMAGE_WIDTH		640
#define MAX_IMAGE_HEIGHT	640
#define MIN_IMAGE_WIDTH		60
#define MIN_IMAGE_HEIGHT	60
#define GRID_SIZE			20
#define LIGHT_GRID_COLOR	140		
#define DARK_GRID_COLOR		128

// Toolbar panel.
#define TOOLBAR_COLOR						48
#define TOOLBAR_WIDTH						640
#define TOOLBAR_HEIGHT						160
// Load and reset image.
#define LOAD_TEXT							"LOAD"
#define LOAD_TEXT_POS_X						10
#define LOAD_TEXT_POS_Y						MAX_IMAGE_HEIGHT + 10
#define LOAD_BUTTON_POS_X					10
#define LOAD_BUTTON_POS_Y					MAX_IMAGE_HEIGHT + 30 
#define LOAD_BUTTON_SIZE					60
#define RESET_BUTTON_POS_X					10
#define RESET_BUTTON_POS_Y					MAX_IMAGE_HEIGHT + 100 
#define RESET_BUTTON_SIZE_WIDTH				60
#define RESET_BUTTON_SIZE_HEIGHT			24
// Resolution.
#define RES_TEXT							"RESOLUTION"
#define RES_TEXT_POS_X						100
#define RES_TEXT_POS_Y						MAX_IMAGE_HEIGHT + 10
#define RES_WIDTH_TEXT						"W"
#define RES_WIDTH_TEXT_POS_X				100
#define RES_WIDTH_TEXT_POS_Y				MAX_IMAGE_HEIGHT + 50
#define RES_HEIGHT_TEXT						"H"
#define RES_HEIGHT_TEXT_POS_X				100
#define RES_HEIGHT_TEXT_POS_Y				MAX_IMAGE_HEIGHT + 100
#define RES_WIDTH_TRACKBAR_POS_X			120
#define RES_WIDTH_TRACKBAR_POS_Y			MAX_IMAGE_HEIGHT + 30
#define RES_HEIGHT_TRACKBAR_POS_X			120
#define RES_HEIGHT_TRACKBAR_POS_Y			MAX_IMAGE_HEIGHT + 80
#define RES_TRACKBER_SIZE					120
#define RES_FIXEDRATIO_CHECKBOX_TEXT		"FIXED RATIO"
#define RES_FIXEDRATIO_CHECKBOX_TEXT_POS_X	100
#define RES_FIXEDRATIO_CHECKBOX_TEXT_POS_Y	MAX_IMAGE_HEIGHT + 135
// Pixel Point Processing.
#define COLOR_CONTRAST_TEXT					"COLOR CONTRAST"
#define COLOR_CONTRAST_TEXT_POS_X			275
#define COLOR_CONTRAST_TEXT_POS_Y			MAX_IMAGE_HEIGHT + 10
#define COLOR_CURVE_IMG_1_POS_X				275
#define COLOR_CURVE_IMG_1_POS_Y				MAX_IMAGE_HEIGHT + 30
#define APPLY_BUTTON_1_POS_X				340
#define APPLY_BUTTON_1_POS_Y				MAX_IMAGE_HEIGHT + 60
#define COLOR_CURVE_IMG_2_POS_X				275
#define COLOR_CURVE_IMG_2_POS_Y				MAX_IMAGE_HEIGHT + 95
#define APPLY_BUTTON_2_POS_X				340
#define APPLY_BUTTON_2_POS_Y				MAX_IMAGE_HEIGHT + 125
#define COLOR_CURVE_IMAGE_SIZE				60
#define APPLY_BUTTON_SIZE_WIDTH				50
#define APPLY_BUTTON_SIZE_HEIGHT			20
// Pixel Group Processing (Filtering).
#define FILTER_TEXT							"FILTERING"
#define FILTER_TEXT_POS_X					425
#define FILTER_TEXT_POS_Y					MAX_IMAGE_HEIGHT + 10
#define GAUSSIAN_FILTER_BUTTON_TEXT			"GAUSSIAN"
#define GAUSSIAN_FILTER_BUTTON_POS_X		420
#define GAUSSIAN_FILTER_BUTTON_POS_Y		MAX_IMAGE_HEIGHT + 135
#define BILATERAL_FILTER_BUTTON_TEXT		"BILATERAL"
#define BILATERAL_FILTER_BUTTON_POS_X		530
#define BILATERAL_FILTER_BUTTON_POS_Y		MAX_IMAGE_HEIGHT + 135
#define FILTER_BUTTON_SIZE_WIDTH			100
#define FILTER_BUTTON_SIZE_HEIGHT			20
#define FILTER_SIGMAS_TEXT					"SIGMA S"
#define FILTER_SIGMAS_TEXT_POS_X			425
#define FILTER_SIGMAS_TEXT_POS_Y			MAX_IMAGE_HEIGHT + 50
#define FILTER_SIGMAS_TRACKBAR_POS_X		480
#define FILTER_SIGMAS_TRACKBAR_POS_Y		MAX_IMAGE_HEIGHT + 30
#define FILTER_SIGMAR_TEXT					"SIGMA R"
#define FILTER_SIGMAR_TEXT_POS_X			425
#define FILTER_SIGMAR_TEXT_POS_Y			MAX_IMAGE_HEIGHT + 100
#define FILTER_SIGMAR_TRACKBAR_POS_X		480
#define FILTER_SIGMAR_TRACKBAR_POS_Y		MAX_IMAGE_HEIGHT + 80
#define FILTER_TRACKBAR_SIZE				150
#define MIN_FILTER_SIGMA_S					0.0f
#define MAX_FILTER_SIGMA_S					5.0f
#define MIN_FILTER_SIGMA_R					0.0f
#define MAX_FILTER_SIGMA_R					50.0f


// Keyboard event.
#define ESC_KEY		27


// Misc.
#define MAX_STRING_BUFFER_LENGTH	2048


#endif
